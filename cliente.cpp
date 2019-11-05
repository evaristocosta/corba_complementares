#include <iostream>
#include <string>
#include <omniORB4/CORBA.h>
#include "complementares.hh"

using namespace std;

ComplementaresApp::CategoriaComplementares obterTipoAtividade();

void imprimeListaAtividades(ComplementaresApp::AtividadesComplementares* listaAtividades);

int main(int argc, char **argv)
{
    CORBA::ORB_ptr orb;

    //Referência de objeto remoto para a chamada dos métodos
    ComplementaresApp::DepositoAtividades_ptr proxy_obj_remoto = 0;

    // Inicializa o objeto ORB
    orb = CORBA::ORB_init(argc, argv);

    // Busca algum nameService ativo, para encontrar o objeto remoto
    CORBA::Object_var ns_obj = orb->resolve_initial_references("NameService");

    if (!CORBA::is_nil(ns_obj))
    {

        // Encontrou um objeto a partir de NameService, agora deve convertê-lo de
        // objeto CORBA para um NamingContext
        CosNaming::NamingContext_ptr nc = CosNaming::NamingContext::_narrow(ns_obj);

        // Prepara o nome a ser buscado no NameService
        CosNaming::Name name;
        name.length(1);
        name[0].id = CORBA::string_dup("ComplementaresLucas");
        name[0].kind = CORBA::string_dup("");

        // Resolve o nome descrito, em busca de um objeto
        ::CORBA::Object_ptr obj_remoto_corba = nc->resolve(name);

        // Caso encontre, converte o objeto CORBA para um objeto Calculadora
        if (!CORBA::is_nil(obj_remoto_corba))
        {
            proxy_obj_remoto = ComplementaresApp::DepositoAtividades::_narrow(obj_remoto_corba);
        }
        else
        {
            cerr << "Objeto obtido é nulo. Abortando..." << endl;
            exit(1);
        }
    }
    else
    {
        cerr << "Objeto obtido é nulo. Abortando..." << endl;
        exit(1);
    }

    if (CORBA::is_nil(proxy_obj_remoto))
    {
        cerr << "Objeto remoto do serviço é nulo. Abortando..." << endl;
        exit(1);
    }


    int opcao = 0;
    do {
        cout << "Digite: " << endl;
        cout << "1 - Cadastrar atividade" << endl;
        cout << "2 - Contar horas cadastradas" << endl;
        cout << "3 - Atividades de um aluno" << endl;
        cout << "4 - Esvaziar armazenamento" << endl;
        cout << "5 - Remover atividade de aluno" << endl;
        cout << "6 - Sair" << endl
             << endl;

        cout << "Opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            /* code */
            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        case 5:
            /* code */
            break;

        case 6:
            /* code */
            break;

        default:
            break;
        }
    } while (opcao != 6);
}
