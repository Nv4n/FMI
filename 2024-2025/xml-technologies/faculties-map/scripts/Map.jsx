import Place from '@material-design-icons/svg/two-tone/place.svg';
import KML from "ol/format/KML";
import VectorSource from "ol/source/Vector";
import Icon from "ol/style/Icon";
import Fill from "ol/style/Fill";
import Stroke from "ol/style/Stroke";
import Style from "ol/style/Style";
import Text from "ol/style/Text";
import { useEffect, useState } from "react";

import MapWidget from "@scripts/MapWidget";

export default function Map({ url, feature, onFeaturesLoaded }) {
    const [vectorSource, setVectorSource] = useState(null);

    useEffect(() => {
        async function fetchFeatures() {
            const result = await fetch(url);
            const mapData = await result.text();
            const kml = new KML({ defaultStyle: createStyle() });
            const features = kml.readFeatures(mapData, { featureProjection: 'EPSG:3857' });

            const source = new VectorSource();
            source.addFeatures(features);
            setVectorSource(source);

            onFeaturesLoaded(features);
        }
        fetchFeatures()
            .catch(console.error);
    }, [url]);

    return <MapWidget layerSource={vectorSource} feature={feature} />;
}

function createStyle() {
    return [
        new Style({
            image: new Icon({ src: Place, size: [32, 32] }),
            text: new Text({
                justify: 'right',
                fill: new Fill({ color: 'black' }),
                placement: 'line',
                offsetX: -100,
                stroke: new Stroke({ color: 'white', width: 5 }),
            }),
        })
    ];
}
