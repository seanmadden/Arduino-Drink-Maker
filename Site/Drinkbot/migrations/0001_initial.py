# -*- coding: utf-8 -*-
import datetime
from south.db import db
from south.v2 import SchemaMigration
from django.db import models


class Migration(SchemaMigration):

    def forwards(self, orm):
        # Adding model 'Ingredient'
        db.create_table(u'Drinkbot_ingredient', (
            ('Id', self.gf('django.db.models.fields.PositiveIntegerField')(primary_key='true')),
            ('name', self.gf('django.db.models.fields.CharField')(max_length='100')),
        ))
        db.send_create_signal(u'Drinkbot', ['Ingredient'])

        # Adding model 'Drink'
        db.create_table(u'Drinkbot_drink', (
            ('Id', self.gf('django.db.models.fields.PositiveIntegerField')(primary_key='true')),
            ('name', self.gf('django.db.models.fields.CharField')(max_length='50')),
        ))
        db.send_create_signal(u'Drinkbot', ['Drink'])

        # Adding M2M table for field ingredients on 'Drink'
        db.create_table(u'Drinkbot_drink_ingredients', (
            ('id', models.AutoField(verbose_name='ID', primary_key=True, auto_created=True)),
            ('drink', models.ForeignKey(orm[u'Drinkbot.drink'], null=False)),
            ('ingredient', models.ForeignKey(orm[u'Drinkbot.ingredient'], null=False))
        ))
        db.create_unique(u'Drinkbot_drink_ingredients', ['drink_id', 'ingredient_id'])


    def backwards(self, orm):
        # Deleting model 'Ingredient'
        db.delete_table(u'Drinkbot_ingredient')

        # Deleting model 'Drink'
        db.delete_table(u'Drinkbot_drink')

        # Removing M2M table for field ingredients on 'Drink'
        db.delete_table('Drinkbot_drink_ingredients')


    models = {
        u'Drinkbot.drink': {
            'Id': ('django.db.models.fields.PositiveIntegerField', [], {'primary_key': "'true'"}),
            'Meta': {'object_name': 'Drink'},
            'ingredients': ('django.db.models.fields.related.ManyToManyField', [], {'to': u"orm['Drinkbot.Ingredient']", 'symmetrical': 'False'}),
            'name': ('django.db.models.fields.CharField', [], {'max_length': "'50'"})
        },
        u'Drinkbot.ingredient': {
            'Id': ('django.db.models.fields.PositiveIntegerField', [], {'primary_key': "'true'"}),
            'Meta': {'object_name': 'Ingredient'},
            'name': ('django.db.models.fields.CharField', [], {'max_length': "'100'"})
        }
    }

    complete_apps = ['Drinkbot']