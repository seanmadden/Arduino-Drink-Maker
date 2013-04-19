from django.db import models

# Create your models here.


class Ingredient(models.Model):
    Id = models.PositiveIntegerField(primary_key='true')
    name = models.CharField(max_length='100')

    def __unicode__(self):
        return self.name


class Drink(models.Model):
    Id = models.PositiveIntegerField(primary_key='true')
    name = models.CharField(max_length='50')
    ingredients = models.ManyToManyField(Ingredient)

    def __unicode__(self):
        return self.name
