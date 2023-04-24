project = "lss_py"
version = 0.1.0


.PHONY: install_dev
install_dev:
	poetry run python setup.py develop


.PHONY: build
build:
	conan install . --build=missing
	conan build .

	poetry run python setup.py sdist bdist_wheel
