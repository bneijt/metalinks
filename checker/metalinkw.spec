# This is a spec file for pyinstaller "compiler" at http://pyinstaller.python-hosting.com/

a = Analysis([os.path.join(HOMEPATH,'support\\_mountzlib.py'), os.path.join(HOMEPATH,'support\\useUnicode.py'), 'guitk.py'],
             pathex=[os.getcwd()])
pyz = PYZ(a.pure)
exe = EXE(pyz, a.scripts, a.binaries, name="metalinkw.exe", console=0)