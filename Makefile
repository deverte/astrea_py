PROJECT = astrea

VENV=.venv
PYTHON=$(VENV)/bin/python3
PIP=$(VENV)/bin/pip3


.PHONY: build
build:
	$(PYTHON) -m build --no-isolation --wheel


.PHONY: env
env:
	python3 -m venv $(VENV)
	$(PIP) install -r requirements.txt


.PHONY: publish
publish:
	$(PYTHON) -m twine upload --repository astro ./dist/*


.PHONY: clear
clear:
	rm -rf .pytest_cache
	rm -rf src/*.egg-info
	rm -rf build
	rm -rf dist
	rm -rf wheelhouse
	rm -f CMakeUserPresets.json


.PHONY: install
install:
	$(PIP) install dist/${PROJECT}-*.whl


.PHONY: uninstall
uninstall:
	$(PIP) uninstall ${PROJECT} -y


.PHONY: test
test:
	$(PYTHON) -m pytest