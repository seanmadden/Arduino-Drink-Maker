__author__ = 'Sean'

from django.contrib import admin
from Drinkbot.models import Ingredient, Drink

admin.site.register(Drink)
admin.site.register(Ingredient)
