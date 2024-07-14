# miniRT
MiniRT - Raytracing engine written in C

## Overview
<img width="1919" alt="image" src="https://github.com/seongmik-s-team/miniRT/assets/44383895/1a89d2a0-3dd4-4a7b-9af4-c7c70fb269bc">

## Getting Started

### System Requirements
- macOS or Linux operating system

### Installation and Build
1. Clone the repository.
```bash
git clone https://github.com/seongmik-s-team/miniRT.git
cd miniRT
```
2. Run the build script.
```
make
```

### Execution
After the build is complete, you can run the program with the following command.
```bash
./miniRT [scene].rt
```

## Usage
- Press the `W`, `A`, `S`, `D` keys to move the camera.
- Press the `↑`, `←`, `↓`, `→` keys to rotate the camera.
- Press the `R` keys to render high quality image.
- Press the `ESC` key to exit the program during rendering.

## Coding Convention
- commit message 형식 : ex. [MERGE] temp commit
- issue 제목 형식 : ex. [BUG] leaks 발생 문제
- pull request 제목 형식 : ex. [BUGFIX] leaks 문제 해결
- 함수가 복잡하면 주석 달기
- 수식 관련은 무조건 주석

