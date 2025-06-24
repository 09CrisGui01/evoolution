BUILD_DIR = 'build/%{cfg.buildcfg}'
OBJECT_DIR = BUILD_DIR..'/objs/%{cfg.buildcfg}'
BINARY_DIR = 'binary/${cfg.platform}/%{cfg.buildcfg}'
SOURCE_DIR = 'source'
TEST_DIR = 'test'

workspace 'Evoolution'
location './'
startproject 'evoolution'
configurations { 'Alpha', 'Beta', 'Gamma' }
platforms { 'Linux64' }


filter 'configurations:Alpha'
runtime 'Debug'
symbols 'On'
optimize 'OFf'
defines { 'DEBUG' }

filter 'configurations:Beta'
runtime 'Release'
symbols 'On'
optimize 'Debug'
defines { 'DEBUG' }

filter 'configurations:Gamma'
runtime 'Release'
symbols 'Off'
optimize 'Full'
defines { 'NDEBUG' }

filter {}


filter 'platforms:Linux*'
system 'linux'

filter {}


filter 'platforms:*64'
architecture 'x86_64'

filter 'platforms:*32'
architecture 'x86'

filter {}


project 'evoolution'
targetname 'evoolution'
kind 'StaticLib'
language 'C'
cdialect 'C23'
staticruntime 'Default'
systemversion 'latest'
warnings 'Extra'
fatalwarnings { 'All' }
targetdir( BINARY_DIR )
objdir( OBJECT_DIR )

files { SOURCE_DIR..'/*.c', SOURCE_DIR..'/*.h' }
removefiles { TEST_DIR..'/*' }
--includedirs { SOURCE_DIR }


project 'test-evoolution'
targetname 'test-evoolution'
kind 'ConsoleApp'
language 'C'
cdialect 'C23'
staticruntime 'Default'
systemversion 'latest'
warnings 'Extra'
--fatalwarnings { 'All' }
targetdir( BINARY_DIR )
objdir( OBJECT_DIR )

files { TEST_DIR..'/*.c', TEST_DIR..'/*.h' }
--includedirs { SOURCE_DIR }

links 'evoolution'
