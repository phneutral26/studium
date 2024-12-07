project('linked_list', 'c',
  version : '1.0',
  default_options : ['warning_level=2', 'c_std=c11'])

# Specify the source files
src_files = files(
  'src/main.c',
  'src/linked_list.c'
)

# Define the executable
executable('linked_list_app', src_files,
  include_directories : include_directories('src'))

