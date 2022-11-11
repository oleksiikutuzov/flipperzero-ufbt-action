# flipperzero-ufbt-action

[![Test action](https://github.com/oleksiikutuzov/flipperzero-ufbt-action/actions/workflows/test_action.yml/badge.svg?branch=main)](https://github.com/oleksiikutuzov/flipperzero-ufbt-action/actions/workflows/test_action.yml)

## Inputs

> **Note**
> You should checkout your repository to some directory, so that ufbt is not in your repo root
> ```
> ── runner_home
>   ├── fap-dir
>   └── flipperzero-ufbt
> ```

`fap-dir` is required. Path to a folder where your repository is checked out

`channel` is not required. Can be `dev`, `rc`, `release`. Default option is `dev`.

## Caching

This workflow will save ufbt cache for your repository as you run it and automatically update it as needed. [More about managing caches](https://docs.github.com/en/actions/using-workflows/caching-dependencies-to-speed-up-workflows#managing-caches)

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
