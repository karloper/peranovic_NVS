project('daytime', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++17', 'warning_level=3', 'werror=true'])

inc_dir = include_directories(['include', get_option('asio_include_dir'), get_option('timeutils_include_dir')]) 


thread_dep = dependency('threads')
src_client = ['src/daytime_client/main.cpp']
src_server = ['src/daytime_server/main.cpp']

executable('client',
           sources : src_client,
           include_directories : inc_dir,
           dependencies : thread_dep
          )

executable('server',
           sources : src_server,
           include_directories : inc_dir,
           dependencies : thread_dep
          )
