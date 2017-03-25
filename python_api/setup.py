from setuptools import setup, Extension

fac_module = Extension('fac_module', sources=["fac_module.c"])
setup(ext_modules=[fac_module])
