project('dyn_array',
        'c',
        'cpp',
  default_options : ['c_std=c11', 'warning_level=2']
)

src_files = files(
  'src/dyn_array.c',
  'src/main.c'
)

executable('dyn_array',
  src_files,
  include_directories: 'include',
  install : false)