<h1 align="center">๐ฃ minitalk</h1>

<p align="center">
	<b><i>Minitalk is a 42 school project that consists in creating a small client-server data exchange program using UNIX signals.</i></b><br>
</p>

<p align="center">
	<img alt="Top used language" src="https://img.shields.io/github/languages/top/okbrandon/minitalk?color=success"/>
	<img alt="Norminette run" src="https://github.com/okbrandon/minitalk/actions/workflows/42-norminette.yml/badge.svg"/>
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/okbrandon/minitalk"/>
</p>

## ๐ Table of Contents

- [๐ Table of Contents](#-table-of-contents)
- [๐ฆ Installation](#-installation)
- [๐ Usage](#-usage)
- [๐ Example](#-example)

## ๐ฆ Installation

Clone the repository from GitHub:
```sh
git clone https://github.com/okbrandon/minitalk.git
```

Compile the `client` executable:
```sh
make client
```

Compile the `server` executable:
```sh
make server
```

Compile both executables:
```sh
make
```

## ๐ Usage

Run the server first:
```sh
./server
```
> You have to run the server before the client to get the PID.

Then run the client:
```sh
./client [PID] [message]
```
> The PID is the one displayed by the server. The message is the message you want to send to the server.

## ๐ Example

Terminal 1:
```sh
$> ./server
    __  ________   _______________    __    __ __
   /  |/  /  _/ | / /  _/_  __/   |  / /   / //_/
  / /|_/ // //  |/ // /  / / / /| | / /   / ,<
 / /  / // // /|  // /  / / / ___ |/ /___/ /| |
/_/  /_/___/_/ |_/___/ /_/ /_/  |_/_____/_/ |_|
               ยปยป PID: 8285 ยซยซ

```

Terminal 2:
```sh
$> ./client 8285 "Hello World!"
```

Terminal 1:
```sh
$> ./server
    __  ________   _______________    __    __ __
   /  |/  /  _/ | / /  _/_  __/   |  / /   / //_/
  / /|_/ // //  |/ // /  / / / /| | / /   / ,<
 / /  / // // /|  // /  / / / ___ |/ /___/ /| |
/_/  /_/___/_/ |_/___/ /_/ /_/  |_/_____/_/ |_|
               ยปยป PID: 8285 ยซยซ

Hello World!
```

Terminal 2:
```sh
$> ./client 8285 "Hello World!"
8285: Successfully got your message! โ
```

[โฌ Back to Top](#-table-of-contents)

## ๐ Meta

bsoubaig โ bsoubaig@student.42nice.fr