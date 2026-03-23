from setuptools import setup, Extension

module1 = Extension('MyTestModule', sources = ['testmodule.cc'])

setup (name = 'PackageTestModule',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])
