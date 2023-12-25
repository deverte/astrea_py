project = astrea
version = 0.7.0


.PHONY: update-version
update-version:
	perl -i -pe 's/version\s=\s\".*\"/version = \"${version}\"/g' pyproject.toml
	perl -i -pe 's/version\s=\s.*/version = ${version}/g' setup.cfg


.PHONY: build
build:
	$(MAKE) update-version
	python setup.py bdist_wheel


.PHONY: publish
publish:
	python -m twine upload --repository astro ./dist/*


.PHONY: clear
clear:
	rm -rf ${project}.egg-info
	rm -rf build
	rm -rf dist
	rm -rf wheelhouse
	rm -f CMakeUserPresets.json


.PHONY: install
install:
	poetry run pip install dist/${project}-*.whl


.PHONY: uninstall
uninstall:
	poetry run pip uninstall ${project} -y


.PHONY: test
test:
	poetry run python -m pytest