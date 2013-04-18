# Create your views here.
from django.http import HttpResponse
from django.shortcuts import render_to_response
from Drinkbot.models import Drink


def index(request):
    return HttpResponse("Hello world. Let's Drink!")


def detail(request, drink_id):
    drink = Drink.objects.get(pk=drink_id)
    ingList = list(drink.ingredients.all())
    ings = ', '.join([ing.name for ing in ingList])
    return HttpResponse("You are looking at beverage: %s which has ingredients: %s" % (drink.name, ings))


def view_page(request, page_name):
    try:
        page = Drink.objects.get(pk=page_name)
    except Drink.DoesNotExist:
        return render_to_response('create.htm', {'page_name', page_name})