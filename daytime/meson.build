project('daytime', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++17', 'warning_level=3', 'werror=true'])

inc_dir = include_directories(['include'])
#                               get_option('json_include_dir')])

src = ['src/main.cpp'
      ]
thread_dep = dependency('threads')


executable('daytime',
           sources : src,
           include_directories : inc_dir,
		   dependencies : thread_dep
          )

