version = "0.2.2" # setup.cfg


.PHONY: build
build:
	poetry run python setup.py bdist_wheel


.PHONY: publish
publish:
	# git tag -a v${version} -m "Release v${version}"
	# git push origin --tags
	python -m twine upload --repository astro ./dist/*
