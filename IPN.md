- Endpoint: OfferWall Notice URL

- Method: `POST`

- Params:
    + `point`: Integer
    + `currency`: String (Your OfferWall Currency)
    + `transaction_id`: String, Unique transaction ID from Adsota
    + `rate`: Integer (Your OfferWall Rate)
    + `app_id`: Integer, App ID
    + `campaign_id`: Integer, Your Campaign ID
    + `target`: String, Your target
    + `state`: String, Your state
    + `hash`: `md5`({`point`}{`currency`}{`transaction_id`}{`rate`}{`app_id`}{`campaign_id`}{`target`}{`state`}{`secret_key`})

`secret_key`: OfferWall secret key, It's allocated when you create the AdUnit