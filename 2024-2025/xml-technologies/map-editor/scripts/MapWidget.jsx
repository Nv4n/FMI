import PlaceIcon from '@material-design-icons/svg/two-tone/place.svg';
import { Map, View } from 'ol';
import { Draw } from 'ol/interaction';
import TileLayer from 'ol/layer/Tile';
import VectorLayer from 'ol/layer/Vector';
import { fromLonLat } from 'ol/proj';
import OSM from 'ol/source/OSM';
import { Fill, Icon, Stroke, Style, Text } from 'ol/style';
import { useEffect, useRef } from "react";

const DEFAULT_CENTER = fromLonLat([23.3217583, 42.697128]);

const DEFAULT_ZOOM = 14;

export default function MapWidget({ layerSource }) {
    const mapContainerRef = useRef(null);
    const mapRef = useRef(null);

    useEffect(() => {
        if (mapRef.current === null) {
            const container = mapContainerRef.current;
            mapRef.current = createMap(container);
        }
        const map = mapRef.current;
        let addPointInteraction;

        if (layerSource) {
            const layer = createVectorLayer(layerSource);
            addPointInteraction = new Draw({
                source: layerSource,
                type: 'Point',
            });
            map.addLayer(layer);
            map.addInteraction(addPointInteraction);
        }

        map.setView(createDefaultView());

        return () => {
            map.setView(createDefaultView());
            map.setLayers(createDefaultMapLayers());
            if (addPointInteraction) {
                map.removeInteraction(addPointInteraction);
            }
        };
    }, [layerSource]);

    return  <div className="map" ref={mapContainerRef} />;
};

function createMap(container) {
    return new Map({
        target: container,
        layers: createDefaultMapLayers(),
    });
}

function createDefaultMapLayers() {
    return [new TileLayer({ source: new OSM() })];
}

function createVectorLayer(source) {
    return new VectorLayer({
        source,
        style: (feature) => new Style({
            image: new Icon({
                src: PlaceIcon,
                size: [32, 32],
            }),
            text: new Text({
                text: feature.get('name'),
                justify: 'left',
                fill: new Fill({ color: 'black' }),
                offsetY: -25,
                offsetX: -5,
                stroke: new Stroke({ color: 'white', width: 5 }),
            }),
        }),
    });
}

function createDefaultView() {
    return new View({
        center: DEFAULT_CENTER,
        zoom: DEFAULT_ZOOM,
    });
}
