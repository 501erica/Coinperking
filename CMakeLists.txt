# 最小バージョン要件の設定
cmake_minimum_required(VERSION 3.15)

# プロジェクト名設定
project(Coinperking 
	VERSION 1.0.0
        LANGUAGES CXX
)

# C++要件
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 標準のテストフラグ付与
include(CTest)
enable_testing()

# Main ソースディレクトリの追加
add_subdirectory(source)

if(BUILD_TESTING)
  # googletest の取得とテストソースディレクトリの追加
  include(cmake/deps.cmake)
  # テストソースディレクトリの追加
  add_subdirectory(testsource)
endif()
# ============================
# インストール設定
# ============================
# CMAKE_INSTALL_PREFIX 未指定時のデフォルト
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Install path" FORCE)
endif()

# =========================
# CPack 設定
# =========================
set(CPACK_PACKAGE_NAME "coinperking")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")

# パッケージの概要
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Coinperking project with core library and executable")
set(CPACK_PACKAGE_VENDOR "Your Company")

# 出力形式（必要に応じて追加）
set(CPACK_GENERATOR "ZIP")

# アーキテクチャを自動で反映
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})
set(CPACK_RPM_PACKAGE_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})

# インクルード必須
include(CPack)
