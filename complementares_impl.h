#include <omniORB4/CORBA.h>
#include <iostream>
#include <string>
#include "complementares.hh"

class Complementares_impl
    : virtual public POA_ComplementaresApp::DepositoAtividades,
      public PortableServer::RefCountServantBase {
   public:
    inline Complementares_impl() {
        listaAtividades = new ::ComplementaresApp::AtividadesComplementares();
        listaAtividades->length(100);
        qtdeAtividades = 0;
    };

    virtual ::CORBA::Boolean cadastrarAtividade(
        const ::ComplementaresApp::AtividadeComplementar &at);
    virtual ::CORBA::Long contarHorasCadastradas(::CORBA::Long RA);
    virtual ::ComplementaresApp::AtividadesComplementares *atividadesCadastradas(::CORBA::Long RA);
    virtual void removerTodas(void);
    virtual ::CORBA::Boolean removerAtividade(
        const ::ComplementaresApp::AtividadeComplementar &at);

   private:
    ::ComplementaresApp::AtividadesComplementares *listaAtividades;
    int qtdeAtividades;
};

inline ::CORBA::Boolean Complementares_impl::cadastrarAtividade(
    const ::ComplementaresApp::AtividadeComplementar &at) {
    if (qtdeAtividades == listaAtividades->length()) {
        return false;
    } else {
        (*listaAtividades)[qtdeAtividades] = at;
        qtdeAtividades++;
        return true;
    }
}

inline ::CORBA::Long Complementares_impl::contarHorasCadastradas(
    ::CORBA::Long RA) {
    long horasTotal = 0;
    for (int i = 0; i < qtdeAtividades; i++) {
        if (RA == (*listaAtividades)[i].RA) {
            horasTotal += (*listaAtividades)[i].numeroHoras;
        }
    }

    return horasTotal;
}
inline ::ComplementaresApp::AtividadesComplementares *
Complementares_impl::atividadesCadastradas(::CORBA::Long RA) {
    int contadorRetorno = 0;
    for (int i = 0; i < qtdeAtividades; i++) {
        if (RA == (*listaAtividades)[i].RA) {
            contadorRetorno++;
        }
    }

    ::ComplementaresApp::AtividadesComplementares *listaRetorno =
        new ::ComplementaresApp::AtividadesComplementares();
    listaRetorno->length(contadorRetorno);

    contadorRetorno = 0;

    for (int i = 0; i < qtdeAtividades; i++) {
        if (RA == (*listaAtividades)[i].RA) {
            (*listaRetorno)[contadorRetorno] = (*listaAtividades)[i];
            contadorRetorno++;
        }
    }

    return listaRetorno;
}
inline void Complementares_impl::removerTodas(void) { qtdeAtividades = 0; }
inline ::CORBA::Boolean Complementares_impl::removerAtividade(
    const ::ComplementaresApp::AtividadeComplementar &at) {
    ::ComplementaresApp::AtividadeComplementar atividadeBuscada(at);
    std::string descricao(atividadeBuscada.descricao);
    std::string url(atividadeBuscada.urlCertificado);
    int i;

    for (i = 0; i < qtdeAtividades; i++) {
        if (atividadeBuscada.RA == (*listaAtividades)[i].RA ||
            (atividadeBuscada.numeroHoras ==
             (*listaAtividades)[i].numeroHoras) ||
            (descricao.compare((*listaAtividades)[i].descricao)) ||
            (url.compare((*listaAtividades)[i].urlCertificado)) ||
            (atividadeBuscada.categoria == (*listaAtividades)[i].categoria)) {
            break;
        }
    }

    if (i == qtdeAtividades) {
        return false;
    } else {
        (*listaAtividades)[i] = (*listaAtividades)[qtdeAtividades - 1];
        qtdeAtividades--;
        return true;
    }
}