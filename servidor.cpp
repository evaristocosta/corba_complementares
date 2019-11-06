#include <omniORB4/CORBA.h>
#include <iostream>
#include <string>
#include "complementares.hh"
#include "complementares_impl.h"

using namespace std;

int main(int argc, char *argv[]) {
    CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);
    CORBA::Object_var poa_obj = orb->resolve_initial_references("RootPOA");

    PortableServer::POA_var poa = PortableServer::POA::_narrow(poa_obj);
    PortableServer::POAManager_var mgr = poa->the_POAManager();

    Complementares_impl *servente = new Complementares_impl();
    CORBA::Object_var servente_obj = poa->servant_to_reference(servente);
    CORBA::Object_var ns_obj = orb->resolve_initial_references("NameService");

    CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(ns_obj);

    if (CORBA::is_nil(nc)) {
        cerr << "Objeto de nome de serviço é nulo. Abortando..." << endl;
        exit(1);
    }

    CosNaming::Name name;
    name.length(1);
    name[0].id = CORBA::string_dup("DepositoAtividades");
    name[0].kind = CORBA::string_dup("");

    cout << "Vinculando o serviço" << endl;
    nc->rebind(name, servente_obj);

    cout << "Objeto pronto para ser usado" << endl;
    mgr->activate();
    orb->run();
}
