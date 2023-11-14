version = "0.5.4" # pyproject.toml, setup.cfg


.PHONY: build
build:
	python setup.py bdist_wheel


.PHONY: publish
publish:
	python -m twine upload --repository astro ./dist/*


.PHONY: clear
clear:
	rm -rf astrea.egg-info
	rm -rf build
	rm -rf dist
	rm -rf wheelhouse
	rm -f CMakeUserPresets.json


.PHONY: install
install:
	poetry run pip install dist/astrea-*.whl


.PHONY: uninstall
uninstall:
	poetry run pip uninstall astrea -y


.PHONY: test
test:
	poetry run python -m pytest