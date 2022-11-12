# flipperzero-ufbt-action

[![Test action](https://github.com/oleksiikutuzov/flipperzero-ufbt-action/actions/workflows/test_action.yml/badge.svg?branch=main)](https://github.com/oleksiikutuzov/flipperzero-ufbt-action/actions/workflows/test_action.yml)

## Inputs

### `path`

Is **not required**. Sets the path to a folder where your fap source code is located if it is not in repository root.

### `channel`

Is **not required**. Sets a channel, from which SDK should be pulled. Can be `dev`, `rc`, `release`. When not specified, defaults to `dev`.

### `lint_only`

Is **not required**. Will only lint your code without building. Can be `true` or `false`. When not specified, defaults to `false`.

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

    - name: Build
      uses: oleksiikutuzov/flipperzero-ufbt-action@v1
      with:
        channel: rc
```

Example of a workflow, that will pull SDK from default `dev` channel and lint your code located in `lightmeter-fap` directory:
```yml
name: Lint code

on: [push]

jobs:
   lint:
    runs-on: ubuntu-latest

    steps:
    - name: Checkout
      uses: actions/checkout@v3

    - name: Lint
      uses: oleksiikutuzov/flipperzero-ufbt-action@v1
      with:
        path: lightmeter-fap
        lint_only: true
```

# Revision History
### Version v1.4.2
- Inputs naming overhaul

### Version v1.4.1
- Inputs naming overhaul

### Version v1.4.0
- Support for lint command

### Version v1.3.2
- Do not use external action for jq

### Version v1.3.1
- Automatically set artifact name to fap name

### Version v1.3
- Push artifact after successful bild

### Version v1.2.3
- Added `channel` input to set SDK channel

### Version v1.0
- First release
