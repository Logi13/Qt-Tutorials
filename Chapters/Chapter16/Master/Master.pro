TEMPLATE = subdirs

SUBDIRS += \
    CityUI \
    fileio

# Dependancies
CityUI.depends = fileio
