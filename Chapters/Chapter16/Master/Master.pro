TEMPLATE = subdirs

SUBDIRS += \
    CityUI \
    fileio \
    fileIO_1 \
    untitled

# Dependancies
CityUI.depends = fileio
