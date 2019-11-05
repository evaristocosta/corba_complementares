#include <iostream>
#include <omniORB4/CORBA.h>
#include <string>
#include "complementares.hh"

class Complementares_impl : virtual public POA_ComplementaresApp::DepositoAtividades, public PortableServer::RefCountServantBase
{
public:
    inline Complementares_impl()
    {
        listaAtividades = new ::ComplementaresApp::AtividadesComplementares();
        listaAtividades->length(100);
        qtdeAtividades = 0;
    };

    virtual ::CORBA::Boolean cadastrarAtividade(const ::ComplementaresApp::AtividadeComplementar &at);
    virtual ::CORBA::Long contarHorasCadastradas(::CORBA::Long RA);
    virtual ::ComplementaresApp::AtividadesComplementares *atividadesCadastradas(::CORBA::Long RA);
    virtual void removerTodas();
    virtual ::CORBA::Boolean removerAtividade(const ::ComplementaresApp::AtividadeComplementar &at);

private:
    ::ComplementaresApp::AtividadesComplementares *listaAtividades;
    int qtdeAtividades;
};

inline ::CORBA::Boolean Complementares_impl::cadastrarAtividade(const ::ComplementaresApp::AtividadeComplementar &at)
{
    if (qtdeAtividades == listaAtividades->length())
    {
        return false;
    }
    else
    {
        (*listaAtividades)[qtdeAtividades] = at;
        qtdeAtividades++;
        return true;
    }
}

inline ::CORBA::Long Complementares_impl::contarHorasCadastradas(::CORBA::Long RA)
{
}
inline ::ComplementaresApp::AtividadesComplementares *Complementares_impl::atividadesCadastradas(::CORBA::Long RA)
{
}
inline void Complementares_impl::removerTodas() 
{
}
inline ::CORBA::Boolean Complementares_impl::removerAtividade(const ::ComplementaresApp::AtividadeComplementar &at)
{
    // criar uma string a partir do valor de estado
    // passado por paarâmetro, para aproveitar o método
    // compare de string
    ::ComplementaresApp::AtividadeComplementar atividadeBuscada(at);

    int i;
    for (i = 0; i < qtdeAtividades; i++)
    {
        if (atividadeBuscada.RA == (*listaAtividades)[i].RA)
        {
            break;
        }
    }

    if (i == qtdeAtividades)
    {
        return false;
    }
    else
    {
        (*listaAtividades)[i] = (*listaAtividades)[qtdeAtividades - 1];
        qtdeAtividades--;
        return true;
    }
}