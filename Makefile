.PHONY: build
build:
	poetry run python setup.py sdist bdist_wheel


.PHONY: publish
publish:
	python -m twine upload --repository astro ./dist/*
