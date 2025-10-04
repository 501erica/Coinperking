  find_package(GTest CONFIG QUIET)
  if(NOT GTest_FOUND)
    message(STATUS "Building tests...")
    include(FetchContent)

    # GoogleTestの取得と有効化（testsource で使うため）
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG v1.17.0
    )
    # インストール不要＆gmockも一緒に
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
  endif()