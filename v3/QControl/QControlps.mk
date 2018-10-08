
QControlps.dll: dlldata.obj QControl_p.obj QControl_i.obj
	link /dll /out:QControlps.dll /def:QControlps.def /entry:DllMain dlldata.obj QControl_p.obj QControl_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del QControlps.dll
	@del QControlps.lib
	@del QControlps.exp
	@del dlldata.obj
	@del QControl_p.obj
	@del QControl_i.obj
