
#ifdef _WINDOWS
# pragma warning(pop)
# undef ALL_WARNINGS_ARE_DISABLED
#elif defined ( __llvm__ )
# pragma clang diagnostic pop
# undef ALL_WARNINGS_ARE_DISABLED
#endif
