# Docs

The documentation is built using [MkDocs](https://www.mkdocs.org/), making it easy to write, maintain, and publish project docs in Markdown format.

## Project setup

### Requirements

- [Python 3.10+](https://www.python.org/downloads/)
- [Visual Studio Code](https://code.visualstudio.com/Download) ([Python](https://marketplace.visualstudio.com/items?itemName=ms-python.python) + [Pylance](https://marketplace.visualstudio.com/items?itemName=ms-python.vscode-pylance) extensions)

### Create virtual environment

```sh
python -m venv env
```

### Activate virtual environment

#### Windows

##### PowerShell

```sh
.\env\Scripts\Activate.ps1
```

If an “Execution Policy” error appears, you need to allow, for example:

```sh
Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy RemoteSigned
```

##### CMD

```sh
env\Scripts\activate.bat
```

#### Linux / MacOS (bash, zsh)

```sh
source env/bin/activate
```

#### Linux / MacOS (Fish shell)

```sh
source env/bin/activate.fish
```

### Install dependencies

```sh
pip install -r requirements.txt
```

### Development (hot reload)

```sh
mkdocs serve
```

### Build for production

```sh
mkdocs build
```
