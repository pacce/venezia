project('venezia', 'cpp', version: '0.1.0')

sources       = []
headers       = include_directories('include')
dependencies  = []

venezia_dep = declare_dependency(
    include_directories : headers
  , dependencies        : dependencies
  )

executable(
  'main'
  , 'source/main.cpp'
  , dependencies  : venezia_dep
  )

if not meson.is_subproject()
  subdir('tests')
endif
