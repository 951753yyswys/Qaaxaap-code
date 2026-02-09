{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    gcc13 
    cmake
    ninja
    #pkg-config
  ];

  # 运行时依赖
  buildInputs = with pkgs; [
    #boost
    #eigen
    #opencv
    # 其他库...
  ];

  # 环境变量
  shellHook = ''
    export CC=gcc
    export CXX=g++
    # 调试信息优化
    export CFLAGS="-O2 -g3"
    export CXXFLAGS="-O2 -g3 -std=c++20"
    if [ -z "$IN_NIX_SHELL" ] || [ -z "$NIX_SHELL_PRESERVE_PROMPT" ]; then
      export SHELL=${pkgs.zsh}/bin/zsh
      exec ${pkgs.zsh}/bin/zsh
    fi
    echo "C++开发环境已激活"
  '';
    
}
