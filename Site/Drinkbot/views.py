# Create your views here.
from django.shortcuts import render, get_object_or_404
from Drinkbot.models import Drink


def index(request):
    drinkList = Drink.objects.all()
    context = {'drinkList': drinkList}
    return render(request, 'Drinkbot/index.html', context)


def detail(request, drink_id):
    drink = get_object_or_404(Drink, pk=drink_id)
    ingList = list(drink.ingredients.all())
    return render(request, 'Drinkbot/detail.html', {'drink': drink,
                                                    'inglist': ingList})
