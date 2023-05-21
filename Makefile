version = "0.2.8" # pyproject.toml, setup.cfg


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