gcc learning_fmod.c fmod_lib/lib/libfmod.dylib
install_name_tool -change @rpath/libfmod.dylib ./fmod_lib/lib/libfmod.dylib a.out
