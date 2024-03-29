// This file is generated by omniidl (C++ backend)- omniORB_4_2. Do not edit.
#ifndef __complementares_hh__
#define __complementares_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef  USE_stub_in_nt_dll
# define USE_stub_in_nt_dll_NOT_DEFINED_complementares
#endif
#ifndef  USE_core_stub_in_nt_dll
# define USE_core_stub_in_nt_dll_NOT_DEFINED_complementares
#endif
#ifndef  USE_dyn_stub_in_nt_dll
# define USE_dyn_stub_in_nt_dll_NOT_DEFINED_complementares
#endif






#ifdef USE_stub_in_nt_dll
# ifndef USE_core_stub_in_nt_dll
#  define USE_core_stub_in_nt_dll
# endif
# ifndef USE_dyn_stub_in_nt_dll
#  define USE_dyn_stub_in_nt_dll
# endif
#endif

#ifdef _core_attr
# error "A local CPP macro _core_attr has already been defined."
#else
# ifdef  USE_core_stub_in_nt_dll
#  define _core_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _core_attr
# endif
#endif

#ifdef _dyn_attr
# error "A local CPP macro _dyn_attr has already been defined."
#else
# ifdef  USE_dyn_stub_in_nt_dll
#  define _dyn_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _dyn_attr
# endif
#endif



_CORBA_MODULE ComplementaresApp

_CORBA_MODULE_BEG

  enum CategoriaComplementares { cultural, palestra, curso, externa /*, __max_CategoriaComplementares=0xffffffff */ };
  typedef CategoriaComplementares& CategoriaComplementares_out;

  struct AtividadeComplementar {
    typedef _CORBA_ConstrType_Variable_Var<AtividadeComplementar> _var_type;

    
    ::CORBA::Long RA;

    ::CORBA::String_member descricao;

    CategoriaComplementares categoria;

    ::CORBA::Long numeroHoras;

    ::CORBA::String_member urlCertificado;

  

    void operator>>= (cdrStream &) const;
    void operator<<= (cdrStream &);
  };

  typedef AtividadeComplementar::_var_type AtividadeComplementar_var;

  typedef _CORBA_ConstrType_Variable_OUT_arg< AtividadeComplementar,AtividadeComplementar_var > AtividadeComplementar_out;

  class AtividadesComplementares_var;

  class AtividadesComplementares : public _CORBA_Unbounded_Sequence< AtividadeComplementar >  {
  public:
    typedef AtividadesComplementares_var _var_type;
    inline AtividadesComplementares() {}
    inline AtividadesComplementares(const AtividadesComplementares& _s)
      : _CORBA_Unbounded_Sequence< AtividadeComplementar > (_s) {}

    inline AtividadesComplementares(_CORBA_ULong _max)
      : _CORBA_Unbounded_Sequence< AtividadeComplementar > (_max) {}
    inline AtividadesComplementares(_CORBA_ULong _max, _CORBA_ULong _len, AtividadeComplementar* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Unbounded_Sequence< AtividadeComplementar > (_max, _len, _val, _rel) {}

  

    inline AtividadesComplementares& operator = (const AtividadesComplementares& _s) {
      _CORBA_Unbounded_Sequence< AtividadeComplementar > ::operator=(_s);
      return *this;
    }
  };

  class AtividadesComplementares_out;

  class AtividadesComplementares_var {
  public:
    inline AtividadesComplementares_var() : _pd_seq(0) {}
    inline AtividadesComplementares_var(AtividadesComplementares* _s) : _pd_seq(_s) {}
    inline AtividadesComplementares_var(const AtividadesComplementares_var& _s) {
      if (_s._pd_seq)  _pd_seq = new AtividadesComplementares(*_s._pd_seq);
      else             _pd_seq = 0;
    }
    inline ~AtividadesComplementares_var() { if (_pd_seq)  delete _pd_seq; }
      
    inline AtividadesComplementares_var& operator = (AtividadesComplementares* _s) {
      if (_pd_seq)  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline AtividadesComplementares_var& operator = (const AtividadesComplementares_var& _s) {
      if (&_s != this) {
        if (_s._pd_seq) {
          if (!_pd_seq)  _pd_seq = new AtividadesComplementares;
          *_pd_seq = *_s._pd_seq;
        }
        else if (_pd_seq) {
          delete _pd_seq;
          _pd_seq = 0;
        }
      }
      return *this;
    }
    inline AtividadeComplementar& operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline AtividadesComplementares* operator -> () { return _pd_seq; }
    inline const AtividadesComplementares* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator AtividadesComplementares& () const { return *_pd_seq; }
#else
    inline operator const AtividadesComplementares& () const { return *_pd_seq; }
    inline operator AtividadesComplementares& () { return *_pd_seq; }
#endif
      
    inline const AtividadesComplementares& in() const { return *_pd_seq; }
    inline AtividadesComplementares&       inout()    { return *_pd_seq; }
    inline AtividadesComplementares*&      out() {
      if (_pd_seq) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline AtividadesComplementares* _retn() { AtividadesComplementares* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class AtividadesComplementares_out;
    
  private:
    AtividadesComplementares* _pd_seq;
  };

  class AtividadesComplementares_out {
  public:
    inline AtividadesComplementares_out(AtividadesComplementares*& _s) : _data(_s) { _data = 0; }
    inline AtividadesComplementares_out(AtividadesComplementares_var& _s)
      : _data(_s._pd_seq) { _s = (AtividadesComplementares*) 0; }
    inline AtividadesComplementares_out(const AtividadesComplementares_out& _s) : _data(_s._data) {}
    inline AtividadesComplementares_out& operator = (const AtividadesComplementares_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline AtividadesComplementares_out& operator = (AtividadesComplementares* _s) {
      _data = _s;
      return *this;
    }
    inline operator AtividadesComplementares*&()  { return _data; }
    inline AtividadesComplementares*& ptr()       { return _data; }
    inline AtividadesComplementares* operator->() { return _data; }

    inline AtividadeComplementar& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    AtividadesComplementares*& _data;

  private:
    AtividadesComplementares_out();
    AtividadesComplementares_out& operator=(const AtividadesComplementares_var&);
  };

#ifndef __ComplementaresApp_mDepositoAtividades__
#define __ComplementaresApp_mDepositoAtividades__
  class DepositoAtividades;
  class _objref_DepositoAtividades;
  class _impl_DepositoAtividades;
  
  typedef _objref_DepositoAtividades* DepositoAtividades_ptr;
  typedef DepositoAtividades_ptr DepositoAtividadesRef;

  class DepositoAtividades_Helper {
  public:
    typedef DepositoAtividades_ptr _ptr_type;

    static _ptr_type _nil();
    static _CORBA_Boolean is_nil(_ptr_type);
    static void release(_ptr_type);
    static void duplicate(_ptr_type);
    static void marshalObjRef(_ptr_type, cdrStream&);
    static _ptr_type unmarshalObjRef(cdrStream&);
  };

  typedef _CORBA_ObjRef_Var<_objref_DepositoAtividades, DepositoAtividades_Helper> DepositoAtividades_var;
  typedef _CORBA_ObjRef_OUT_arg<_objref_DepositoAtividades,DepositoAtividades_Helper > DepositoAtividades_out;

#endif

  // interface DepositoAtividades
  class DepositoAtividades {
  public:
    // Declarations for this interface type.
    typedef DepositoAtividades_ptr _ptr_type;
    typedef DepositoAtividades_var _var_type;

    static _ptr_type _duplicate(_ptr_type);
    static _ptr_type _narrow(::CORBA::Object_ptr);
    static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);
    
    static _ptr_type _nil();

    static inline void _marshalObjRef(_ptr_type, cdrStream&);

    static inline _ptr_type _unmarshalObjRef(cdrStream& s) {
      omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId,s);
      if (o)
        return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
      else
        return _nil();
    }

    static inline _ptr_type _fromObjRef(omniObjRef* o) {
      if (o)
        return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
      else
        return _nil();
    }

    static _core_attr const char* _PD_repoId;

    // Other IDL defined within this scope.
    
  };

  class _objref_DepositoAtividades :
    public virtual ::CORBA::Object,
    public virtual omniObjRef
  {
  public:
    // IDL operations
    ::CORBA::Boolean cadastrarAtividade(const ::ComplementaresApp::AtividadeComplementar& at);
    ::CORBA::Long contarHorasCadastradas(::CORBA::Long RA);
    AtividadesComplementares* atividadesCadastradas(::CORBA::Long RA);
    void removerTodas();
    ::CORBA::Boolean removerAtividade(const ::ComplementaresApp::AtividadeComplementar& at);

    // Constructors
    inline _objref_DepositoAtividades()  { _PR_setobj(0); }  // nil
    _objref_DepositoAtividades(omniIOR*, omniIdentity*);

  protected:
    virtual ~_objref_DepositoAtividades();

    
  private:
    virtual void* _ptrToObjRef(const char*);

    _objref_DepositoAtividades(const _objref_DepositoAtividades&);
    _objref_DepositoAtividades& operator = (const _objref_DepositoAtividades&);
    // not implemented

    friend class DepositoAtividades;
  };

  class _pof_DepositoAtividades : public _OMNI_NS(proxyObjectFactory) {
  public:
    inline _pof_DepositoAtividades() : _OMNI_NS(proxyObjectFactory)(DepositoAtividades::_PD_repoId) {}
    virtual ~_pof_DepositoAtividades();

    virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
    virtual _CORBA_Boolean is_a(const char*) const;
  };

  class _impl_DepositoAtividades :
    public virtual omniServant
  {
  public:
    virtual ~_impl_DepositoAtividades();

    virtual ::CORBA::Boolean cadastrarAtividade(const ::ComplementaresApp::AtividadeComplementar& at) = 0;
    virtual ::CORBA::Long contarHorasCadastradas(::CORBA::Long RA) = 0;
    virtual AtividadesComplementares* atividadesCadastradas(::CORBA::Long RA) = 0;
    virtual void removerTodas() = 0;
    virtual ::CORBA::Boolean removerAtividade(const ::ComplementaresApp::AtividadeComplementar& at) = 0;
    
  public:  // Really protected, workaround for xlC
    virtual _CORBA_Boolean _dispatch(omniCallHandle&);

  private:
    virtual void* _ptrToInterface(const char*);
    virtual const char* _mostDerivedRepoId();
    
  };


_CORBA_MODULE_END



_CORBA_MODULE POA_ComplementaresApp
_CORBA_MODULE_BEG

  class DepositoAtividades :
    public virtual ComplementaresApp::_impl_DepositoAtividades,
    public virtual ::PortableServer::ServantBase
  {
  public:
    virtual ~DepositoAtividades();

    inline ::ComplementaresApp::DepositoAtividades_ptr _this() {
      return (::ComplementaresApp::DepositoAtividades_ptr) _do_this(::ComplementaresApp::DepositoAtividades::_PD_repoId);
    }
  };

_CORBA_MODULE_END



_CORBA_MODULE OBV_ComplementaresApp
_CORBA_MODULE_BEG

_CORBA_MODULE_END





#undef _core_attr
#undef _dyn_attr

inline void operator >>=(ComplementaresApp::CategoriaComplementares _e, cdrStream& s) {
  ::operator>>=((::CORBA::ULong)_e, s);
}

inline void operator <<= (ComplementaresApp::CategoriaComplementares& _e, cdrStream& s) {
  ::CORBA::ULong _0RL_e;
  ::operator<<=(_0RL_e,s);
  if (_0RL_e <= ComplementaresApp::externa) {
    _e = (ComplementaresApp::CategoriaComplementares) _0RL_e;
  }
  else {
    OMNIORB_THROW(MARSHAL,_OMNI_NS(MARSHAL_InvalidEnumValue),
                  (::CORBA::CompletionStatus)s.completion());
  }
}



inline void
ComplementaresApp::DepositoAtividades::_marshalObjRef(::ComplementaresApp::DepositoAtividades_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}



#ifdef   USE_stub_in_nt_dll_NOT_DEFINED_complementares
# undef  USE_stub_in_nt_dll
# undef  USE_stub_in_nt_dll_NOT_DEFINED_complementares
#endif
#ifdef   USE_core_stub_in_nt_dll_NOT_DEFINED_complementares
# undef  USE_core_stub_in_nt_dll
# undef  USE_core_stub_in_nt_dll_NOT_DEFINED_complementares
#endif
#ifdef   USE_dyn_stub_in_nt_dll_NOT_DEFINED_complementares
# undef  USE_dyn_stub_in_nt_dll
# undef  USE_dyn_stub_in_nt_dll_NOT_DEFINED_complementares
#endif

#endif  // __complementares_hh__

