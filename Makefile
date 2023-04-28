export project = lss_py
export version = 0.1.6


.PHONY: install_dev
install_dev:
	poetry run python setup.py develop


.PHONY: build
build:
	conan install . --build=missing
	conan build .

	poetry run python setup.py sdist bdist_wheel


.PHONY: publish
publish:
	python -m twine upload --repository astro ./dist/*
