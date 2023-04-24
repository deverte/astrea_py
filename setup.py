import pathlib
import setuptools
import shutil


__version__ = '0.1.0'


package_path = pathlib.Path('lss')

shared_object = []
shared_object.extend([
    *pathlib.Path('build/Release').glob('lss_py*.so'),
    *pathlib.Path('build/Release').glob('lss_py*.dll'),
])
shared_object = shared_object[0]

shutil.copy(shared_object, package_path / shared_object.name)


setuptools.setup(
    name='lss',
    version=__version__,
    packages=['lss'],
    package_data={
        'lss': ['lss_py*.so', 'lss_py*.dll'],
    },
    include_package_data=True,
)