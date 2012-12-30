from os.path import exists
from os import remove
from shutil import rmtree

def set_options(ctx):
  ctx.tool_options('compiler_cxx')

def configure(ctx):
  ctx.check_tool('compiler_cxx')
  ctx.check_tool('node_addon')

def clean(cln):
  if exists('build'): rmtree('build')
  if exists('mt19937.node'): remove('mt19937.node')

def build(ctx):
  t = ctx.new_task_gen('cxx', 'shlib', 'node_addon')
  t.cxxflags = ['-g', '-O3', '-minline-all-stringops', '-fPIC']
  t.target = 'mt19937'
  t.source = [
    'src/mt19937.cc',
  ]
  t.install_path = '..'
