# flipperzero-ufbt-action

[![Test action](https://github.com/oleksiikutuzov/flipperzero-ufbt-action/actions/workflows/test_action.yml/badge.svg?branch=main)](https://github.com/oleksiikutuzov/flipperzero-ufbt-action/actions/workflows/test_action.yml)

## Inputs

> **Note**
> You should checkout your repository to some directory, so that ufbt is not in your repo root

`fap-dir` is required. Path to a folder where your repository is checked out

`channel` is not required. Can be `dev`, `rc`, `release`. Default option is `dev`.

## Usage example

```yml
name: Build FAP

on: [push]

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
    - name: Checkout
      uses: actions/checkout@v3
      with:
        path: flipperzero-lightmeter
        submodules: 'true'
        
    - name: Build
      uses: oleksiikutuzov/flipperzero-ufbt-action@v1
      with:
        fap-dir: flipperzero-lightmeter
        channel: rc
```
