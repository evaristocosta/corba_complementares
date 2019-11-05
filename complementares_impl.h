#include <iostream>
#include <omniORB4/CORBA.h>
#include <string>
#include "complementares.hh"

class complementares_impl : virtual public POA_ComplementaresApp, public PortableServer::RefCountServantBase {
    public:
        inline complementares_impl() {
            listaAtividades = new ::ComplementaresApp::AtividadesComplementares();
            listaAtividades->length(100);
            qtdeAtividades = 0;
        }

        virtual ::CORBA::Boolean cadastrarAtividade(const ::ComplementaresApp::AtividadeComplementar &at);
        virtual ::CORBA::Long contarHorasCadastradas(::CORBA::Long RA);
        virtual ::ComplementaresApp::AtividadesComplementares *atividadesCadastradas(::CORBA::Long RA);
        virtual ::CORBA::Boolean removerAtividade(const ::ComplementaresApp::AtividadeComplementar &at);

    private:
        ::ComplementaresApp::AtividadesComplementares* listaAtividades;
        int qtdeAtividades;
};

inline ::CORBA::Boolean complementares_impl::cadastrarAtividade(const ::ComplementaresApp::AtividadeComplementar &at) {
    if (qtdeAtividades == listaAtividades->length()) {
        return false;
    } else {
        (*listaAtividades)[qtdeAtividades] = at;
        qtdeAtividades++;
        return true;
    }
}