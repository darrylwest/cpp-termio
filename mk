#!/usr/bin/env bash
#
# dpw@plaza.localdomain | 2024-12-13 03:28:43
#
#

set -eu

export project=termio

# parse the cli
while [[ $# -gt 0 ]]
do
    case $1 in
        all)
            ./mk pull 
            ./mk clobber init test demo

            exit 0
        ;;
        init)
            /bin/rm -fr build/
            # [ -d dep-cache ] || mkdir dep-cache
            (mkdir build && cd build && cmake ..)

            shift
        ;;
        build)
            clear

            # cmake --build build/ 
            (cd build && time make -j4 || exit 1)

            shift
        ;;
        unit|test)
            (cd build && make -j4 && ctest --output-on-failure)
            ./build/termio_tests

            shift
        ;;
        format)
            clang-format -i include/termio/*.hpp src/*.cpp tests/*.cpp
            git status -s

            shift
        ;;
        demo|examples)
            ./build/simple-colors

            shift
        ;;
        clean)
            (cd build && make clean && /bin/rm -f unit)
        
            shift
        ;;
        clobber)
            /bin/rm -fr build/

            shift
        ;;
        watch)
            watchexec -c -w src/ -w include/ -w examples/ -e h,hpp,cpp ./mk clobber init build unit examples

            exit 0
        ;;

        pull)
            git pull

            shift
        ;;

        help)
            echo "Targets:"
            echo ""
            echo "   init     : run the cmake command to create the build folder"
            echo "   build    : compile cryptor to the build folder"
            echo "   format   : runs clang-format over includes and src"
            echo "   watch    : run watcher over source and include"
            echo "   pull     : pull the latest repo changes"
            echo "   clean    : remove binary builds but leave the build folder"
            echo "   clobber  : remove the entire build folder"
            echo "   help     : show this help"
            
            exit 0
        ;;

        build)
            cd src && pwd && make && make unit

            shift
        ;;
        *)
            ./mk help
            exit 0
        ;;

    esac
done


