__author__ = 'Sean'

from django.conf.urls import patterns, url
from Drinkbot import views

urlpatterns = patterns('',
    url(r'^$', views.index, name='index'),
    # ex: /drinkbot/5/
    url(r'^(?P<drink_id>\d+)/$', views.detail, name='detail'),
)