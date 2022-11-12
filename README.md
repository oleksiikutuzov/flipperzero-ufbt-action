# flipperzero-ufbt-action

[![Test action](https://github.com/oleksiikutuzov/flipperzero-ufbt-action/actions/workflows/test_action.yml/badge.svg?branch=main)](https://github.com/oleksiikutuzov/flipperzero-ufbt-action/actions/workflows/test_action.yml)

## Inputs

> **Note**
> You should checkout your repository to some directory, so that ufbt is not in your repo root
> ```
> ── runner_home
>    ├── fap-dir
>    └── flipperzero-ufbt
> ```

### `fap-dir` 

Is **required**. Sets the path to a folder where your repository is checked out.

### `channel` 

Is **not required**. Sets a channel, from which SDK should be pulled. Can be `dev`, `rc`, `release`. When not specified, defaults to `dev`.

### `lint` 

Is **not required**. Will lint your code instead of building. Can be `true` or `false`. When not specified, defaults to `false`.

## Caching

This workflow will save ufbt cache for your repository as you run it and automatically update it as needed. [More about managing caches](https://docs.github.com/en/actions/using-workflows/caching-dependencies-to-speed-up-workflows#managing-caches)

## Usage examples

Example of a workflow, that will pull SDK from `rc` channel and build your fap:

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

Eample of a workflow, that will pull SDK from default `dev` channel and lint your code:
```yml
name: Lint code

on: [push]

jobs:        
   lint:
    runs-on: ubuntu-latest

    steps:
    - name: Checkout
      uses: actions/checkout@v3
      with:
        path: flipperzero-lightmeter
        submodules: 'true'
        
    - name: Lint
      uses: oleksiikutuzov/flipperzero-ufbt-action@v1
      with:
        fap-dir: flipperzero-lightmeter
        lint: true
```

