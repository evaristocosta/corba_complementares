#include <omniORB4/CORBA.h>
#include <iostream>
#include <string>
#include "complementares.hh"

using namespace std;

ComplementaresApp::CategoriaComplementares tiposAtividade();

void printListaComplementares(
    ComplementaresApp::AtividadesComplementares* listaComplementares);

int main(int argc, char** argv) {
    CORBA::ORB_ptr orb;

    ComplementaresApp::DepositoAtividades_ptr proxy_obj_remoto = 0;
    orb = CORBA::ORB_init(argc, argv);

    CORBA::Object_var ns_obj = orb->resolve_initial_references("NameService");

    if (!CORBA::is_nil(ns_obj)) {
        CosNaming::NamingContext_ptr nc =
            CosNaming::NamingContext::_narrow(ns_obj);

        CosNaming::Name name;
        name.length(1);
        name[0].id = CORBA::string_dup("DepositoAtividades");
        name[0].kind = CORBA::string_dup("");

        ::CORBA::Object_ptr obj_remoto_corba = nc->resolve(name);

        if (!CORBA::is_nil(obj_remoto_corba)) {
            proxy_obj_remoto = ComplementaresApp::DepositoAtividades::_narrow(
                obj_remoto_corba);
        } else {
            cerr << "Objeto obtido é nulo. Abortando..." << endl;
            exit(1);
        }
    } else {
        cerr << "Objeto obtido é nulo. Abortando..." << endl;
        exit(1);
    }

    if (CORBA::is_nil(proxy_obj_remoto)) {
        cerr << "Objeto remoto do serviço é nulo. Abortando..." << endl;
        exit(1);
    }

    int opcao = 0;
    do {
        cout << "Escolha: " << endl;
        cout << "1 - Cadastrar atividade" << endl;
        cout << "2 - Contar horas cadastradas" << endl;
        cout << "3 - Atividades de um aluno" << endl;
        cout << "4 - Esvaziar armazenamento" << endl;
        cout << "5 - Remover atividade de aluno" << endl;
        cout << "6 - Sair" << endl << endl;

        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                ComplementaresApp::AtividadeComplementar* ac =
                    new ComplementaresApp::AtividadeComplementar();
                string descricao, url;

                cout << "RA do aluno: ";
                cin >> ac->RA;

                cout << "Descricao da atividade: ";
                cin >> descricao;
                ac->descricao = ::CORBA::string_dup(descricao.c_str());

                cout << "Quantidade de horas: ";
                cin >> ac->numeroHoras;

                cout << "URL do certificado: ";
                cin >> url;
                ac->urlCertificado = ::CORBA::string_dup(url.c_str());

                ac->categoria = tiposAtividade();

                proxy_obj_remoto->cadastrarAtividade(*ac);

                break;
            }
            case 2: {
                long ra;

                cout << "Digite o RA para consulta de horas: ";
                cin >> ra;

                long total = proxy_obj_remoto->contarHorasCadastradas(ra);

                if (total) {
                    cout << "Total de horas deste aluno: " << total << endl;
                } else {
                    cout << "Nao existem horas cadastradas para este aluno."
                         << endl;
                }

                break;
            }
            case 3: {
                long ra;

                cout << "Digite o RA para consulta de atividades: ";
                cin >> ra;

                ::ComplementaresApp::AtividadesComplementares* listaRetorno =
                    proxy_obj_remoto->atividadesCadastradas(ra);

                printListaComplementares(listaRetorno);

                break;
            }
            case 4: {
                int certeza = 0;
                cout << "Tem certeza que deseja realizar esta operacao?" << endl;
                cout << "1 - Sim" << endl;
                cout << "0 - Nao" << endl;
                cin >> certeza;

                if (certeza) {
                    proxy_obj_remoto->removerTodas();
                }

                break;
            }
            case 5: {
                ComplementaresApp::AtividadeComplementar* ac =
                    new ComplementaresApp::AtividadeComplementar();
                string descricao, url;

                cout << "RA do aluno: ";
                cin >> ac->RA;

                cout << "Descricao da atividade: ";
                cin >> descricao;
                ac->descricao = ::CORBA::string_dup(descricao.c_str());

                cout << "Quantidade de horas: ";
                cin >> ac->numeroHoras;

                cout << "URL do certificado: ";
                cin >> url;
                ac->urlCertificado = ::CORBA::string_dup(url.c_str());

                ac->categoria = tiposAtividade();

                if(proxy_obj_remoto->removerAtividade(*ac)) {
                    cout << "Atividade removida com sucesso." << endl;
                } else {
                    cout << "Nao foi possivel encontrar esta atividade" << endl;
                }

                break;
            }
            case 6:
                cout << "Terminando..." << endl;
                break;

            default:
                cout << "Operacao invalida" << endl;
        }
    } while (opcao != 6);

    orb->destroy();
}

ComplementaresApp::CategoriaComplementares tiposAtividade() {
    int opcao;

    while (true) {
        cout << "Escolha do tipo de atividade" << endl;
        cout << "Digite:" << endl;
        cout << "1 - Cultural" << endl;
        cout << "2 - Palestra" << endl;
        cout << "3 - Curso" << endl;
        cout << "4 - Externa" << endl << endl;

        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                return ComplementaresApp::cultural;
                break;
            case 2:
                return ComplementaresApp::palestra;
                break;
            case 3:
                return ComplementaresApp::curso;
                break;
            case 4:
                return ComplementaresApp::externa;
                break;
            default:
                cout << "Opcao invalida, escolha outra!" << endl << endl;
        }
    }
}

void printListaComplementares(
    ComplementaresApp::AtividadesComplementares* listaComplementares) {
    if (listaComplementares->length() > 0) {
        cout << " Atividades do aluno " << (*listaComplementares)[0].RA << endl
             << endl;
    }

    for (int i = 0; i < listaComplementares->length(); i++) {
        cout << "Descricao: " << (*listaComplementares)[i].descricao << endl;
        cout << "Quantidade de horas: " << (*listaComplementares)[i].numeroHoras
             << endl;
        cout << "URL: " << (*listaComplementares)[i].urlCertificado << endl;

        switch ((*listaComplementares)[i].categoria) {
            case ::ComplementaresApp::cultural:
                cout << "Tipo: cultural" << endl;
                break;
            case ::ComplementaresApp::palestra:
                cout << "Tipo: palestra" << endl;
                break;
            case ::ComplementaresApp::curso:
                cout << "Tipo: curso" << endl;
                break;
            case ::ComplementaresApp::externa:
                cout << "Tipo: externa" << endl;
                break;
            default:
                cout << "Tipo: desconhecido" << endl;
                break;
        }
        cout << endl;
    }
}