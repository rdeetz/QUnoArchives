
QEngineps.dll: dlldata.obj QEngine_p.obj QEngine_i.obj
	link /dll /out:QEngineps.dll /def:QEngineps.def /entry:DllMain dlldata.obj QEngine_p.obj QEngine_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del QEngineps.dll
	@del QEngineps.lib
	@del QEngineps.exp
	@del dlldata.obj
	@del QEngine_p.obj
	@del QEngine_i.obj
