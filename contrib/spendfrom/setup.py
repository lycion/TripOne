from distutils.core import setup
setup(name='tonespendfrom',
      version='1.0',
      description='Command-line utility for tripone "coin control"',
      author='Gavin Andresen',
      author_email='gavin@triponefoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
