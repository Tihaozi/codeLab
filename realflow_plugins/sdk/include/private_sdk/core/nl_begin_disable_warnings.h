

#ifdef _WINDOWS
# ifdef ALL_WARNINGS_ARE_DISABLED
#   error "All warnings are disabled."
# endif

# pragma warning(push,0)
# define ALL_WARNINGS_ARE_DISABLED
#elif defined ( __llvm__ )
# ifdef ALL_WARNINGS_ARE_DISABLED
#   error "All warnings are disabled."
# endif

# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wall"
# define ALL_WARNINGS_ARE_DISABLED
#endif
