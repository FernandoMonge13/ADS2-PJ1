# ADS2-PJ1

Para correr este proyecto será necesario tener instalado gtkmm, si no lo tienes usa los siguientes comandos en consola para su instalación:

    sudo apt update
    sudo apt-get install libgtkmm-3.0-dev

Y también se necesita la librería de logging spdlog:

    sudo apt update
    sudo apt install libspdlog-dev


Así como también incluir estas lineas en el CmakeList.txt:

    find_package(PkgConfig)
    pkg_check_modules(GTKMM gtkmm-3.0)
    include_directories(${GTKMM_INCLUDE_DIRS})
    link_directories(${GTKMM_LIBRARY_DIRS})
    target_link_libraries(ADS2_PJ1 ${GTKMM_LIBRARIES})
