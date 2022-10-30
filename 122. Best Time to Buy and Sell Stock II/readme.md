# best dp perspective for me
there are 2 choices at any given point. finding the maximum profit at both points.
at point n, we can choose to sell or not to sell
the idea is more to find the best profit now if we sell or don't sell
    let's say we sell at this day -> set to last operation sold
        max : 
            the last operation was selling, and you keep that profit
            the last operation was buying, and now you sell by adding the profit
                QS: why just add the profit? what's the price we are buying?
                    profit - buy + sell = profit + (sell - buy) | buy is set by previous
    let's say we don't sell at htis day -> set to last operation bought
        keep the profit of the last operation as buying
        the last operation was selling, now you buy, so the profit has to be reduced by the price
            profit - buy
    do this except for the last one. 
the end is to get a sell; either just last sold and you don't buy, or last is bought and now you sell by adding

where do you consider buying this instead of that? 
what to note: shifting the thought process of filling the dp. A leap of trust I'm taking here.