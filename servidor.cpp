#include <iostream>
#include <string>
#include <omniORB4/CORBA.h>
#include "complementares_impl.h"
#include "complementares.hh"

using namespace std;

int main(int argc, char *argv[])
{
    //Inicialização do objeto ORB
    CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

    // Busca pelo adaptador de objetos raiz, que incluíra nossa calculadora
    CORBA::Object_var poa_obj = orb->resolve_initial_references("RootPOA");

    // Fazer a conversão do POA de objeto CORBA para objeto POA
    PortableServer::POA_var poa = PortableServer::POA::_narrow(poa_obj);
    PortableServer::POAManager_var mgr = poa->the_POAManager();

    // Objeto servente na linguagem nativa do sistema
    Complementares_impl *servente = new Complementares_impl();

    // Criar objeto CORBA correspondente ao servente
    CORBA::Object_var servente_obj =
        poa->servant_to_reference(servente);

    // Obter objeto CORBA correspondente ao servidor de nomes
    CORBA::Object_var ns_obj =
        orb->resolve_initial_references("NameService");

    // Fazer a conversão do objeto CORBA para o objeto de serviço de nome
    CosNaming::NamingContext_var nc =
        CosNaming::NamingContext::_narrow(ns_obj);

    // Verifica se o objeto obtido não é nulo
    if (CORBA::is_nil(nc))
    {
        cerr << "Objeto de nome de serviço é nulo. Abortando..." << endl;
        exit(1);
    }

    // Preparando a estrutura usada na vinculação de serviço
    CosNaming::Name name;
    name.length(1);
    name[0].id = CORBA::string_dup("ComplementaresLucas");
    name[0].kind = CORBA::string_dup("");

    cout << "Vinculando o serviço" << endl;

    // Vinculando o nome Hello ao serviço de hello
    nc->rebind(name, servente_obj);

    cout << "Objeto pronto para ser usado" << endl;

    // Ativando as estrututas neccessárias e iniciando o loop de requisições.
    mgr->activate();
    orb->run();
}
