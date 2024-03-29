#include <omniORB4/CORBA.h>
#include <iostream>
#include <limits>
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
        name[0].id = CORBA::string_dup("ComplementaresLucas");
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

    cout << "-------- SISTEMA DE GERENCIAMENTO DE ATIVIDADES COMPLEMENTARES "
            "-------- "
         << endl << endl;

    string descricao, url;
    long RA, numeroHoras;

    int opcao = 0;
    do {
        cout << "Escolha uma opcao: " << endl;
        cout << "1 - Cadastrar atividade" << endl;
        cout << "2 - Contar horas cadastradas" << endl;
        cout << "3 - Atividades de um aluno" << endl;
        cout << "4 - Esvaziar armazenamento" << endl;
        cout << "5 - Remover atividade de aluno" << endl;
        cout << "6 - Sair" << endl << endl;

        cout << "Opção: ";
        cin >> opcao;

        // reaproveitamento de variaveis
        descricao = "";
        url = "";
        RA = 0;
        numeroHoras = 0;

        if (!isdigit(opcao)) {
            switch (opcao) {
                case 1: {
                    ComplementaresApp::AtividadeComplementar* ac =
                        new ComplementaresApp::AtividadeComplementar();

                    cout << "-------- CADASTRO DE ATIVIDADE --------" << endl;
                    cout << "RA do aluno: ";
                    cin >> RA;

                    cout << "Descricao da atividade: ";
                    cin >> descricao;

                    cout << "Quantidade de horas: ";
                    cin >> numeroHoras;

                    cout << "URL do certificado: ";
                    cin >> url;

                    ac->categoria = tiposAtividade();
                    ac->RA = RA;
                    ac->descricao = ::CORBA::string_dup(descricao.c_str());
                    ac->numeroHoras = numeroHoras;
                    ac->urlCertificado = ::CORBA::string_dup(url.c_str());

                    if (proxy_obj_remoto->cadastrarAtividade(*ac)) {
                        cout << "Atividade cadastrada com sucesso!" << endl;
                        cout << "------------------------" << endl << endl;
                    } else {
                        cout << "Limite de armazenamento atingido!" << endl;
                        cout << "------------------------" << endl << endl;
                    }

                    break;
                }
                case 2: {
                    cout << "-------- CONTAGEM DE HORAS --------" << endl;
                    cout << "Digite o RA para consulta de horas: ";
                    cin >> RA;

                    long total = proxy_obj_remoto->contarHorasCadastradas(RA);

                    if (total) {
                        cout << "Total de horas deste aluno: " << total << "h" << endl;
                        cout << "------------------------" << endl << endl;
                    } else {
                        cout << "Nao existem horas cadastradas para este aluno."
                             << endl;
                        cout << "------------------------" << endl << endl;
                    }

                    break;
                }
                case 3: {
                    cout << "-------- ATIVIDADES DO ALUNO --------" << endl;
                    cout << "Digite o RA para consulta de atividades: ";
                    cin >> RA;

                    ::ComplementaresApp::AtividadesComplementares*
                        listaRetorno =
                            proxy_obj_remoto->atividadesCadastradas(RA);

                    printListaComplementares(listaRetorno);

                    break;
                }
                case 4: {
                    cout << "-------- LIBERAR ARMAZENAMENTO --------" << endl;
                    int certeza = 0;
                    cout << "Tem certeza que deseja realizar esta operacao?"
                         << endl;
                    cout << "1 - Sim" << endl;
                    cout << "0 - Nao" << endl;
                    cin >> certeza;

                    if (certeza == 1) {
                        proxy_obj_remoto->removerTodas();
                        cout << "Armazenamento limpo!" << endl;
                        cout << "------------------------" << endl << endl;
                    } else if (certeza != 0) {
                        cout << "Opcao invalida!" << endl;
                        cout << "------------------------" << endl << endl;
                    }

                    break;
                }
                case 5: {
                    ComplementaresApp::AtividadeComplementar* ac =
                        new ComplementaresApp::AtividadeComplementar();

                    cout << "-------- REMOCAO DE ATIVIDADE --------" << endl;
                    cout << "RA do aluno a ser removido: ";
                    cin >> RA;

                    cout << "Descricao da atividade: ";
                    cin >> descricao;

                    cout << "Quantidade de horas: ";
                    cin >> numeroHoras;

                    cout << "URL do certificado: ";
                    cin >> url;

                    ac->categoria = tiposAtividade();
                    ac->RA = RA;
                    ac->descricao = ::CORBA::string_dup(descricao.c_str());
                    ac->numeroHoras = numeroHoras;
                    ac->urlCertificado = ::CORBA::string_dup(url.c_str());

                    if (proxy_obj_remoto->removerAtividade(*ac)) {
                        cout << "Atividade removida com sucesso." << endl;
                        cout << "------------------------" << endl << endl;
                    } else {
                        cout << "Nao foi possivel encontrar esta atividade"
                             << endl;
                        cout << "------------------------" << endl << endl;
                    }
                    break;
                }
                case 6:
                    cout << "Terminando..." << endl;
                    break;

                default:
                    cout << "Operacao invalida" << endl;
                    cout << "------------------------" << endl << endl;
            }
        } else {
            cout << "Selecione uma opcao valida!" << endl;
            cout << "------------------------" << endl << endl;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
                cout << "Opcao invalida, escolha outra!" << endl;
                cout << "------------------------" << endl << endl;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void printListaComplementares(
    ComplementaresApp::AtividadesComplementares* listaComplementares) {
    if (listaComplementares->length() > 0) {
        cout << "========================" << endl;
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
        cout << "========================" << endl << endl;
    }
}